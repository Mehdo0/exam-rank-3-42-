1.	Comprendre le problème en détail

2.	Diviser en plusieurs étapes similaires (ex: n_queens = placer un reines sur une colonne en s'assurant qu'elle ne peut pas se faire manger)

3.	Cas de base (condition d'arrêt), avoir un 'état' pour vérifier le cas de base (ex: n_queens = indice de chaque reine pour l'état et toute les
	reines sont placées pour la condition d'arrêt)

4.	Essayer (lancer) chaque solution possible à partir de l'état actuelle

5.	Backtracking, revenir en arrière si aucune des conditions n'est juste (ex: n_queens si aucune reines peut être placée sur la col 3, 
	changer l'emplacement de celle sur la col 2)

bool Backtracking(int etat) {
	if (etat_est_complet(etat))
		return (True);
	for (chaque option possible dans etat) {
	appliquerOption(etat, option);
	if (etatEstValide(etat)) {
		if (solutionTrouvee(etat)) {
			return true;
		}
	}
	annulerOption(etat, option);
    }
    return false;
}