INSERT INTO usuari (usu_sobrenom, usu_nom, usu_contrasenya, usu_correu_electronic, usu_data_naixement, usu_modalitat_subscripcio) 
VALUES 
('john_doe', 'John Doe', 'password123', 'john.doe@example.com', '1990-01-01', 'completa'),
('jane_doe', 'Jane Doe', 'securepass456', 'jane.doe@example.com', '1985-05-10', 'cinefil'),
('mike89', 'Michael Brown', 'mypassword789', 'mike.brown@example.com', '2000-12-15', 'infantil'),
('sara_smith', 'Sara Smith', 'qwerty123', 'sara.smith@example.com', '1998-07-22', 'completa'),
('emily_jones', 'Emily Jones', 'abc12345', 'emily.jones@example.com', '1992-03-18', 'cinefil'),
('lucas_w', 'Lucas White', 'passlucas22', 'lucas.white@example.com', '1995-11-10', 'completa'),
('anna_bell', 'Anna Bell', 'annapass33', 'anna.bell@example.com', '1988-04-15', 'cinefil'),
('jack_77', 'Jack Green', 'jacksecure77', 'jack.green@example.com', '2002-08-23', 'infantil'),
('chloe_k', 'Chloe King', 'chloe123king', 'chloe.king@example.com', '1996-02-27', 'completa'),
('oliver_b', 'Oliver Brown', 'brownie1234', 'oliver.brown@example.com', '1999-09-05', 'cinefil');

-- 10 entradas de ejemplo para la tabla 'usuaris'

INSERT INTO contingut (con_titol, con_descripcio, con_qualificacio, con_tipus) 
VALUES 
('Inception', 'A mind-bending thriller about dreams within dreams.', '12+', 'pelicula'),
('The Lion King', 'A young lion prince flees his kingdom.', 'TP', 'pelicula'),
('Breaking Bad', 'A high school teacher turns to cooking meth.', '16+', 'serie'),
('The Office', 'A mockumentary sitcom about office life.', '7+', 'serie'),
('Avengers: Endgame', 'The final showdown against Thanos.', '12+', 'pelicula'),
('Friends', 'A group of friends navigate life and love in NYC.', '7+', 'serie'),
('The Godfather', 'The story of a powerful crime family.', '18+', 'pelicula'),
('Game of Thrones', 'A fantasy epic about the battle for the Iron Throne.', '18+', 'serie'),
('Toy Story', 'Toys come to life and go on adventures.', 'TP', 'pelicula'),
('Stranger Things', 'Kids uncover a supernatural mystery.', '12+', 'serie'),
('Titanic', 'A love story set on the doomed Titanic.', '12+', 'pelicula'),
('The Dark Knight', 'Batman faces off against the Joker.', '12+', 'pelicula'),
('Forrest Gump', 'The life journey of an extraordinary yet simple man.', '12+', 'pelicula'),
('Pulp Fiction', 'Interwoven tales of crime and redemption in Los Angeles.', '18+', 'pelicula'),
('The Matrix', 'A hacker discovers the shocking truth about his reality.', '16+', 'pelicula'),
('The Mandalorian', 'A bounty hunter navigates the galaxy after the fall of the Empire.', '12+', 'serie'),
('The Crown', 'A dramatized history of Queen Elizabeth II and the British royal family.', '12+', 'serie'),
('House of the Dragon', 'The prequel to Game of Thrones about House Targaryen.', '18+', 'serie'),
('Sherlock', 'A modern adaptation of Arthur Conan Doyle`s detective stories.', '16+', 'serie'),
('The Witcher', 'A monster hunter struggles to find his place in a world where people can be crueler than beasts.', '18+', 'serie');

-- 20 entradas de ejemplo para la tabla 'contingut'

INSERT INTO pelicula (pel_titol, pel_data_estrena, pel_duracio) 
VALUES 
('Inception', '2010-07-16', 148),
('The Lion King', '1994-06-24', 89),
('Avengers: Endgame', '2019-04-26', 181),
('The Godfather', '1972-03-24', 175),
('Toy Story', '1995-11-22', 81),
('Titanic', '1997-12-19', 195),
('The Dark Knight', '2008-07-18', 152),
('Forrest Gump', '1994-07-06', 142),
('Pulp Fiction', '1994-10-14', 154),
('The Matrix', '1999-03-31', 136);

-- 10 entradas de ejemplo para la tabla 'pelicula'

INSERT INTO serie (ser_titol, ser_data_estrena) 
VALUES 
('Breaking Bad', '2008-01-20'),
('The Office', '2005-03-24'),
('Friends', '1994-09-22'),
('Game of Thrones', '2011-04-17'),
('Stranger Things', '2016-07-15'),
('The Mandalorian', '2019-11-12'),
('The Crown', '2016-11-04'),
('House of the Dragon', '2022-08-21'),
('Sherlock', '2010-07-25'),
('The Witcher', '2019-12-20');

-- 10 entradas de ejemplo para la tabla 'serie'

INSERT INTO temporada (tem_titol_serie, tem_numero) 
VALUES 
('Breaking Bad', 1),
('Breaking Bad', 2),
('The Office', 1),
('Friends', 1),
('Game of Thrones', 1),
('Stranger Things', 1),
('Stranger Things', 2),
('Game of Thrones', 2),
('Breaking Bad', 3),
('Breaking Bad', 4),
('Breaking Bad', 5),
('The Mandalorian', 1),
('The Mandalorian', 2),
('The Crown', 1),
('The Crown', 2),
('The Crown', 3),
('House of the Dragon', 1),
('Sherlock', 1),
('Sherlock', 2),
('The Witcher', 1),
('The Witcher', 2);

-- 20 entradas de ejemplo para la tabla 'temporada'

INSERT INTO capitol (cap_titol_serie, cap_numero_temporada, cap_numero, cap_titol, cap_data_estrena, cap_qualificacio) 
VALUES 
('Breaking Bad', 1, 1, 'Pilot', '2008-01-20', '16+'),
('Breaking Bad', 1, 2, 'Cat’s in the Bag...', '2008-01-27', '16+'),
('Breaking Bad', 1, 3, '...And the Bag`s in the River', '2008-02-10', '16+'),
('Breaking Bad', 2, 1, 'Seven Thirty/Seven', '2009-03-08', '16+'),
('Breaking Bad', 2, 2, 'Grilled', '2009-03-15', '16+'),
('The Mandalorian', 1, 1, 'Chapter 1: The Mandalorian', '2019-11-12', '12+'),
('The Mandalorian', 1, 2, 'Chapter 2: The Child', '2019-11-15', '12+'),
('The Crown', 1, 1, 'Wolferton Splash', '2016-11-04', '12+'),
('The Crown', 1, 2, 'Hyde Park Corner', '2016-11-11', '12+'),
('House of the Dragon', 1, 1, 'The Heirs of the Dragon', '2022-08-21', '18+'),
('House of the Dragon', 1, 2, 'The Rogue Prince', '2022-08-28', '18+'),
('Sherlock', 1, 1, 'A Study in Pink', '2010-07-25', '16+'),
('Sherlock', 1, 2, 'The Blind Banker', '2010-08-01', '16+'),
('The Witcher', 1, 1, 'The End’s Beginning', '2019-12-20', '18+'),
('The Witcher', 1, 2, 'Four Marks', '2019-12-20', '18+');
('The Office', 1, 1, 'Pilot', '2005-03-24', '7+'),
('Friends', 1, 1, 'The One Where It All Began', '1994-09-22', '7+'),
('Game of Thrones', 1, 1, 'Winter is Coming', '2011-04-17', '18+'),
('Stranger Things', 1, 1, 'The Vanishing of Will Byers', '2016-07-15', '12+'),
('Stranger Things', 2, 1, 'Madmax', '2017-10-27', '12+'),
('Game of Thrones', 2, 1, 'The North Remembers', '2012-04-01', '18+');

-- 20 entradas de ejemplo para la tabla 'capitol'

INSERT INTO relacionat (rel_titol_x, rel_titol_y) 
VALUES 
-- Relaciones entre series
('Breaking Bad', 'The Mandalorian'),
('Breaking Bad', 'The Crown'),
('The Mandalorian', 'House of the Dragon'),
('House of the Dragon', 'The Witcher'),
('Sherlock', 'Breaking Bad'),
-- Relaciones entre películas
('The Dark Knight', 'Pulp Fiction'),
('The Dark Knight', 'The Matrix'),
('Titanic', 'Forrest Gump'),
('Titanic', 'The Lion King'),
('Avengers: Endgame', 'The Matrix'),
-- Relaciones mixtas entre series y películas
('Breaking Bad', 'The Godfather'),
('The Mandalorian', 'Avengers: Endgame'),
('House of the Dragon', 'The Lion King'),
('Sherlock', 'The Dark Knight'),
('The Witcher', 'The Matrix');

-- 15 entradas de ejemplo para la tabla 'relacionat'

INSERT INTO visualitzacio_pelicula (vip_sobrenom_usuari, vip_titol_pelicula, vip_data, vip_nb_visualitzacions) 
VALUES 
('john_doe', 'Titanic', '2023-12-01 20:30:00', 1),
('jane_doe', 'The Dark Knight', '2023-12-05 21:00:00', 2),
('mike89', 'Forrest Gump', '2023-12-10 19:15:00', 1),
('sara_smith', 'Pulp Fiction', '2023-12-12 22:00:00', 3),
('emily_jones', 'The Matrix', '2023-12-15 20:00:00', 2),
('lucas_w', 'Inception', '2023-12-18 21:45:00', 4),
('anna_bell', 'The Lion King', '2023-12-20 18:00:00', 1),
('jack_77', 'Avengers: Endgame', '2023-12-22 19:00:00', 5),
('chloe_k', 'The Godfather', '2023-12-25 20:30:00', 1),
('oliver_b', 'Toy Story', '2023-12-28 17:45:00', 2),
('john_doe', 'The Lion King', '2023-12-01 16:00:00', 1),
('jane_doe', 'Avengers: Endgame', '2023-12-05 22:00:00', 2),
('mike89', 'The Dark Knight', '2023-12-10 20:00:00', 1),
('sara_smith', 'Titanic', '2023-12-12 18:00:00', 3),
('emily_jones', 'The Godfather', '2023-12-15 21:00:00', 2),
('lucas_w', 'Pulp Fiction', '2023-12-18 22:15:00', 4),
('anna_bell', 'Forrest Gump', '2023-12-20 20:30:00', 1),
('jack_77', 'The Matrix', '2023-12-22 18:00:00', 2),
('chloe_k', 'Inception', '2023-12-25 19:00:00', 1),
('oliver_b', 'Avengers: Endgame', '2023-12-28 16:00:00', 2);

-- 20 entradas de ejemplo para la tabla 'visualitzacio_pelicula'

INSERT INTO visualitzacio_capitol (vic_sobrenom_usuari, vic_titol_serie, vic_num_temporada, vic_num_capitol, vic_data, vic_nb_visualitzacions) 
VALUES 
('john_doe', 'Breaking Bad', 1, 1, '2023-12-01 20:30:00', 1),
('jane_doe', 'Breaking Bad', 1, 2, '2023-12-02 21:00:00', 2),
('mike89', 'The Mandalorian', 1, 1, '2023-12-03 19:15:00', 1),
('sara_smith', 'The Mandalorian', 1, 2, '2023-12-04 22:00:00', 3),
('emily_jones', 'The Crown', 1, 1, '2023-12-05 20:00:00', 2),
('lucas_w', 'The Crown', 1, 2, '2023-12-06 21:45:00', 4),
('anna_bell', 'House of the Dragon', 1, 1, '2023-12-07 18:00:00', 1),
('jack_77', 'House of the Dragon', 1, 2, '2023-12-08 19:00:00', 5),
('chloe_k', 'Sherlock', 1, 1, '2023-12-09 20:30:00', 1),
('oliver_b', 'Sherlock', 1, 2, '2023-12-10 17:45:00', 2),
('john_doe', 'The Witcher', 1, 1, '2023-12-11 16:00:00', 1),
('jane_doe', 'The Witcher', 1, 2, '2023-12-12 22:00:00', 2),
('mike89', 'Breaking Bad', 2, 1, '2023-12-13 20:00:00', 1),
('sara_smith', 'Breaking Bad', 2, 2, '2023-12-14 18:00:00', 3),
('emily_jones', 'The Mandalorian', 2, 1, '2023-12-15 21:00:00', 2),
('lucas_w', 'The Mandalorian', 2, 2, '2023-12-16 22:15:00', 4),
('anna_bell', 'The Crown', 2, 1, '2023-12-17 20:30:00', 1),
('jack_77', 'House of the Dragon', 1, 2, '2023-12-18 18:00:00', 2),
('chloe_k', 'The Witcher', 2, 1, '2023-12-19 19:00:00', 1),
('oliver_b', 'Sherlock', 2, 2, '2023-12-20 16:00:00', 2);

-- 20 entradas de ejemplo para la tabla 'visualitzacio_capitol'
