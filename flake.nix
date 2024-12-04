{
    description = "MaxEngine";

    inputs = {
        nixpkgs.url = "github:nixos/nixpkgs/nixos-24.05";
        flake-utils.url  = "github:numtide/flake-utils";
    };

    outputs = { self, nixpkgs, flake-utils, ... }:
        flake-utils.lib.eachDefaultSystem (system:
            let
                cmake_output_binary_name = "projecte_esin";

                pkgs = import nixpkgs { inherit system; };

                build_tools = with pkgs; [ cmake gcc13 pkg-config ];

                debug_tools = with pkgs; [ binutils clang-tools lldb valgrind ];

                runtime_dependencies = with pkgs; [ 
                    mysql80
                    libmysqlconnectorcpp
                ];

                cmake_build = pkgs.stdenv.mkDerivation {
                    pname = cmake_output_binary_name;
                    version = "0.1.0";
                    src = ./.;
                    nativeBuildInputs = build_tools;
                    buildInputs = runtime_dependencies;

                    buildPhase = ''
                        cmake ..
                        make
                    '';

                    installPhase = ''
                        mkdir -p $out/bin
                        cp ${cmake_output_binary_name} $out/bin
                    '';
                };
            in { 
                defaultPackage = cmake_build;

                devShells.default = with pkgs; mkShell {
                    buildInputs = build_tools ++ debug_tools ++ runtime_dependencies;
                    stdenv = pkgs.clangStdenv;
                    shellHook = ''
                        export LD_LIBRARY_PATH=${toString ./external_blobs}:$LD_LIBRARY_PATH
                        export LD_LIBRARY_PATH=${toString ./external_blobs/include/jdbc}:$LD_LIBRARY_PATH
                    '';
                };
            }
        );
}
