print("Entrez la quantité de lignes voulue (>0):")
n = int(input())
# Création d'une matrice n*n
A = [[0 for i in range(n)] for i in range(n)]
for i in range(n):
    # Mise à 1 de la première colone
    A[i][0] = 1
    # Mise à 1 de la diagonale
    A[i][i] = 1
# Chaque "case" est = à la somme de la case du dessus et de la case du dessus à gauche
for i in range(1, n):
    for j in range(1, n):
        A[i][j] = A[i-1][j-1]+A[i-1][j]
# Affichage
for line in A:
    print(line)
