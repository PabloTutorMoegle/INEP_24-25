# PetitFlix - Projecte INEP
## Com compilar:
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

## Com crear la base de dades:
Al directori `sql_scripts` hi ha un arxiu `create_tables.sql` per crear totes les taules de la base de dades.
