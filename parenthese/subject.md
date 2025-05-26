(made by chatgpt)

🧠 Exercice : Parenthèses Apparentées
📝 Objectif
Écrire un programme en C qui identifie et affiche toutes les paires de parenthèses ouvrantes et fermantes correspondantes dans une chaîne de caractères donnée, tout en ignorant les espaces.

📥 Entrée
Le programme reçoit une seule chaîne de caractères en argument de la ligne de commande. Cette chaîne peut contenir :

Des parenthèses ( et )

Des espaces

Aucun autre caractère

Exemple d’appel :


./a.out "( ) ( ( ) )"
📤 Sortie attendue
Le programme doit afficher chaque paire valide de parenthèses, en entourant cette paire par ( au début et ) à la fin, à la même position que dans la chaîne d'origine. Les autres caractères (espaces ou autres) sont remplacés par des espaces, de sorte que seule la paire trouvée soit mise en évidence par des parenthèses.

Exemple :

$ ./a.out "( ) ( ( ) )"
( )         
      ( )   
    (     )
Chaque ligne montre une paire différente de parenthèses détectée dans la chaîne.

📌 Contraintes
Il n’est pas nécessaire de valider la syntaxe globale des parenthèses.

Le programme doit être récursif.

L’affichage doit toujours respecter les positions originales des caractères dans la chaîne d'entrée.

Aucun tableau dynamique ou structure de données complexe n’est nécessaire.

🧪 Autres exemples
Entrée :

$ ./a.out "( ( ) )"
Sortie :

( )     
(     )
🛑 Erreurs
Si le programme ne reçoit pas exactement un argument, il ne doit rien afficher et retourner un code d'erreur (1).