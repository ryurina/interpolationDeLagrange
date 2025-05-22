# Formule de Lagrange

La méthode de Lagrange exprime le polynôme interpolateur sous la forme :

$$
P(x) = \sum_{i=0}^{n} y_i L_i(x)
$$

où $L_i(x)$ sont les polynômes de base de Lagrange définis par :

$$
L_i(x) = \prod_{\substack{j=0 \\ j \neq i}}^{n} \frac{x - x_j}{x_i - x_j}
$$

# Cas Particulier : Degré 2

Pour l'interpolation de degré 2, nous utilisons trois points $(x_0, y_0)$, $(x_1, y_1)$, $(x_2, y_2)$.

## Polynômes de Base

Les trois polynômes de base sont :

$$
L_0(x) = \frac{(x - x_1)(x - x_2)}{(x_0 - x_1)(x_0 - x_2)}
$$

$$
L_1(x) = \frac{(x - x_0)(x - x_2)}{(x_1 - x_0)(x_1 - x_2)}
$$

$$
L_2(x) = \frac{(x - x_0)(x - x_1)}{(x_2 - x_0)(x_2 - x_1)}
$$

## Polynôme Interpolateur

Le polynôme interpolateur de degré 2 s'écrit :

$$
P(x) = y_0 L_0(x) + y_1 L_1(x) + y_2 L_2(x)
$$

# Algorithme et Pseudo-code

## Pseudo-code de l'Interpolation de Lagrange

Voici le pseudo-code général pour l'interpolation de Lagrange de degré 2 :

```text
ALGORITHME InterpolationLagrange
ENTREE: 
    points[3] : tableau de 3 points (xi, yi)
    x : valeur à interpoler
SORTIE: 
    P(x) : valeur du polynôme interpolateur en x

DEBUT
    resultat <- 0
    
    POUR i DE 0 A 2 FAIRE
        Li <- 1  // Polynôme de base Li(x)
        
        POUR j DE 0 A 2 FAIRE
            SI j != i ALORS
                Li <- Li * (x - points[j].x) / (points[i].x - points[j].x)
            FIN SI
        FIN POUR
        
        resultat <- resultat + points[i].y * Li
    FIN POUR
    
    RETOURNER resultat
FIN
