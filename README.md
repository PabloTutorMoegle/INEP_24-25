# PetitFlix - Projecte INEP
## Com compilar
### Dependències: 
- `cmake`
- `gcc`
- `libmysqlconnectorcpp`

### Comandaments
```bash
mkdir build
cd build
cmake ..
make
```

## Com definir els credencials de la base de dades:
S'ha de crear un fitxer `.env` al directori on s'executa el programa amb les claus següents
```bash
HOST=<adreça>:<port>
USER=<usuari>
PASSWORD=<contrasenya>
```

# ↓ BORRAR ABANS D'ENTREGAR ↓

# TODO
## Pablo
- Revisar `CapaDeDades::PasarelaVisualitzarSerie`
- Fer `CapaDeDades::CercadoraVisualitzarSerie`
- Implementar les operacions de CapaDePresentacio
- Fer main
  - El tipus `time_t` et permet obtenir els dies, les hores, els minuts i tal per separat, per poguer fer un cout bonic

## Ari
- Fer `CapaDeDades::PasarelaVisualitzarPelicula`
- Fer `CapaDeDades::CercadoraVisualitzarPelicula`

# DONE
 - De la capa de dades, Usuari i ConnexióBDD està acabat
 - Tota la capa de domini està acabada.
