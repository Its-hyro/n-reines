## Tp2 HPC

# Question 2. 


Quelle fonction de main est testée ?

Dans le fichier test_main.c, la fonction de main. c qui est utilisé est « parse_args ». Les entrées de test ont été choisies suivant plusieurs cas :
- Le cas sans argument ou avec trop d’arguments.
- Le cas avec un argument non valide. (Ex : notanint, -10, 0)
- Le cas avec un argument valide. (Ex : 153, un entier valide)
Il serait peut-être intéressant de tester un cas où l’argument est très grand ou avec des notations scientifiques. Voir si le test marche meme avec une chaine de caractère ou des espaces (12abC), ou encore avec une chaine vide ou nulle. (assert_int_equal [-1, parse_args (2, (char*[]) {« queens », « »})] ;). Il pourrait aussi il y a avoir un cas ou l’on tes les limites inférieures et supérieures des entiers. (Ex : assert_int_equal [INT_MAX, parse_args (2, (char*[]) {« queens », « 2147483647 »})] ; ou encore assert_int_equal [-1, parse_args (2, (char*[]) {« queens », « 2147483648 »})] ;).

# Question 5.

Quel taux de couverture est atteint par nos tests ?

Il semblerai que le taux de couverture est de 100% pour les fichiers test_queens et test_main 


pour n = 2  18 cycles 
pour n = 3  30 cycles
pour n = 4  1406 cycles
pour n = 5  5351 cycles
pour n = 6  2679 
pour n = 7  26644
pour n = 8  72214 
pour n = 9  479450
pour n = 10 993382
pour n = 11 4003497 cycles
pour n = 12 19796884 cycles
pour n = 14 625699016 cycles

on peut tracer ce graphique on constate que le nombre de cycles augmente de manière « exponientiel » cela est surement due au nombre de solutions qui augment elle aussi de manière exponentielle.
