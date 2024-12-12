-- --------------------- Enums --------------------- --
CREATE TABLE modalitat_subscripcio (
    mod_tipus varchar(200) PRIMARY KEY
);
INSERT INTO modalitat_subscripcio (mod_tipus) 
VALUES ('completa'), ('cinefil'), ('infantil');

CREATE TABLE qualificacio_edat (
    qua_qualificacio varchar(200) PRIMARY KEY
);
INSERT INTO qualificacio_edat (qua_qualificacio) 
VALUES ('TP'), ('7+'), ('12+'), ('16+'), ('18+');
-- ------------------------------------------------- --

-- -------------------- Clases --------------------- --
CREATE TABLE usuari (
    usu_sobrenom varchar(200) PRIMARY KEY,
    usu_nom MEDIUMTEXT NOT NULL,
    usu_contrasenya MEDIUMTEXT NOT NULL,
    usu_correu_electronic MEDIUMTEXT UNIQUE NOT NULL,
    usu_data_naixement DATETIME NOT NULL,
    usu_modalitat_subscripcio varchar(200) NOT NULL,
    
    FOREIGN KEY (usu_modalitat_subscripcio) 
        REFERENCES modalitat_subscripcio (mod_tipus)
);

CREATE TABLE contingut (
    con_titol varchar(200) PRIMARY KEY,
    con_descripcio MEDIUMTEXT NOT NULL,
    con_qualificacio varchar(200) NOT NULL,
    con_tipus MEDIUMTEXT NOT NULL,

    FOREIGN KEY (con_qualificacio) 
        REFERENCES qualificacio_edat (qua_qualificacio),

    CONSTRAINT chk_tipus_contingut 
        CHECK (con_tipus IN ('serie', 'pelicula'))
);

CREATE TABLE pelicula (
    pel_titol varchar(200) PRIMARY KEY,
    pel_data_estrena DATETIME NOT NULL,
    pel_duracio INT NOT NULL,

    FOREIGN KEY (pel_titol) 
        REFERENCES contingut (con_titol),
    
    CONSTRAINT chk_pel_duracio 
        CHECK (pel_duracio > 0)
);

CREATE TABLE serie (
    ser_titol varchar(200) PRIMARY KEY,

    FOREIGN KEY (ser_titol) 
        REFERENCES contingut (con_titol)
);

CREATE TABLE temporada (
    tem_titol_serie varchar(200),
    tem_numero INT,
    PRIMARY KEY (tem_titol_serie, tem_numero),

    FOREIGN KEY (tem_titol_serie) 
        REFERENCES serie (ser_titol),

    CONSTRAINT chk_tem_numero 
        CHECK (tem_numero > 0)
);

CREATE TABLE capitol (
    cap_titol_serie varchar(200),
    cap_numero_temporada INT,
    cap_numero INT,
    cap_titol MEDIUMTEXT NOT NULL,
    cap_data_estrena DATETIME NOT NULL,
    cap_qualificacio varchar(200) NOT NULL,

    PRIMARY KEY (cap_titol_serie, cap_numero_temporada, cap_numero),

    FOREIGN KEY (cap_titol_serie, cap_numero_temporada) 
        REFERENCES temporada (tem_titol_serie, tem_numero),

    FOREIGN KEY (cap_qualificacio) 
        REFERENCES qualificacio_edat (qua_qualificacio),

    CONSTRAINT chk_cap_numero 
        CHECK (cap_numero > 0)
);
-- ------------------------------------------------- --

-- ------------------ Associacions ----------------- --
CREATE TABLE relacionat (
    rel_titol_x varchar(200),
    rel_titol_y varchar(200),

    PRIMARY KEY (rel_titol_x, rel_titol_y),

    FOREIGN KEY (rel_titol_x)
        REFERENCES contingut (con_titol),

    FOREIGN KEY (rel_titol_y) 
        REFERENCES contingut (con_titol)
);

CREATE TABLE visualitzacio_pelicula (
    vip_sobrenom_usuari varchar(200),
    vip_titol_pelicula varchar(200),
    vip_data DATETIME NOT NULL,
    vip_nb_visualitzacions INT NOT NULL,

    FOREIGN KEY (vip_sobrenom_usuari) 
        REFERENCES usuari (usu_sobrenom)
        ON DELETE CASCADE,

    FOREIGN KEY (vip_titol_pelicula) 
        REFERENCES pelicula (pel_titol)
        ON DELETE CASCADE,

    CONSTRAINT chk_nb_visualitzacions 
        CHECK (vip_nb_visualitzacions > 0)
);

CREATE TABLE visualitzacio_capitol (
    vic_sobrenom_usuari varchar(200),
    vic_titol_serie varchar(200),
    vic_num_temporada INT,
    vic_num_capitol INT,
    vic_data DATETIME NOT NULL,
    vic_nb_visualitzacions INT NOT NULL,

    PRIMARY KEY (
        vic_sobrenom_usuari, 
        vic_titol_serie, 
        vic_num_temporada, 
        vic_num_capitol
    ),
    
    FOREIGN KEY (vic_sobrenom_usuari) 
        REFERENCES usuari (usu_sobrenom)
        ON DELETE CASCADE,

    FOREIGN KEY (vic_titol_serie, vic_num_temporada, vic_num_capitol) 
        REFERENCES capitol (cap_titol_serie, cap_numero_temporada, cap_numero)
        ON DELETE CASCADE,

    CONSTRAINT chk_nb_visualitzacions 
        CHECK (vic_nb_visualitzacions > 0)
);
-- ------------------------------------------------- --
