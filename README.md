# Modélisation d'un Comportement Addictif  

## Description  
Ce projet propose un **modèle mathématique** décrivant les dynamiques d'addiction. L'objectif est de comprendre l'évolution des comportements addictifs au fil du temps et d'analyser les interactions entre deux individus.  

Nous étudions deux cas :  
1. **Modèle pour une seule personne** : modélisation de l'intensité de l'addiction en fonction de plusieurs paramètres.  
2. **Modèle pour deux personnes** : prise en compte des effets d’influence et d’interactions mutuelles.  

Le modèle est ensuite implémenté en **C++** pour effectuer des simulations et analyser les résultats.

---

## 1. Modèle Mathématique  

### Modèle pour une Personne  
L'évolution de plusieurs variables clés associées à l'addiction est décrite par les équations suivantes :  

$$
\begin{aligned}
    C(t+1) &= (1 - d) C(t) + b \min \{1, 1 - C(t)\} A(t) &C(0) = C_0 \\
    S(t+1) &= S(t) + p \max \{0, S_{\text{max}} - S(t)\} - h C(t) - k A(t) &S(0) = S_0 \\
    E(t+1) &= E(t) - m_E E(t) &E(0) = E_0 \\
    A(t) &= V(t) + R(\lambda(t)) \times q(1 - V(t)), &R(\cdot) \sim \text{Poisson}(\lambda) \\
    \lambda(t+1) &= \lambda(t) + m_\lambda, &\lambda(0) = \lambda_0
\end{aligned}
$$

#### Lois de comportement :  
- $$\psi = C - S - E$$  
- $$V = \min \{1; \max \{\psi, 0\} \}$$  
- Addiction si $$V \approx 1$$  

---

### Modèle pour Deux Personnes  
Ce modèle ajoute des **interactions** entre deux individus \( i \) et \( j \), en introduisant des coefficients d'influence réciproque \( \alpha, \beta, \gamma \).  

Les équations deviennent :  

$$
\begin{aligned}
    C_i(t+1) &= (1 - d) C_i(t) + \alpha A_j(t) C_i(t) + b \min \{1, 1 - C_i(t)\} A_i(t) \\
    S_i(t+1) &= S_i(t) + p_j \max \{0, S_{\text{max}} - S_i(t)\} - h C_i(t) - k A_i(t) \\
    p_j &= p + \beta \exp(-\gamma A_j(t))
\end{aligned}
$$

---

## 2. Implémentation en C++  

### Structure du Code  

Pour garantir modularité et évolutivité, le code est organisé en **classes distinctes** :  

#### **1. Classe `Personne`**  
La classe `Personne` permet de créer un individu et de définir les caractéristiques liées à son addiction.  
- **Attributs** : paramètres du modèle pour un individu.  
- **Constructeurs** : par défaut, par copie et spécifique.  
- **Getters & Setters** : pour accéder et modifier les attributs.  
- **Méthodes supplémentaires** : simplification de la création d’une personne addict ou ordinaire sans connaître les ordres de grandeur des paramètres.  

---

#### **2. Classe Abstraite `Système`**  
La classe `Système` regroupe les paramètres communs aux systèmes modélisant un ou deux individus.  
- Définit les caractéristiques générales du système.  
- Contient la **méthode abstraite `solveSysteme()`**, qui sera définie dans les classes `Systeme1P` et `Systeme2P`.  

---

#### **3. Classe `Systeme1P`**  
Modélise un **système avec une seule personne**.  
- Hérite de `Système`.  
- Contient un attribut `Personne` pour représenter l'individu étudié.  
- Implémente la méthode `solveSysteme()`, qui :  
  - Initialise les paramètres.  
  - Exécute un nombre défini d’itérations pour résoudre le système.  

Un défi majeur est la **génération de nombres aléatoires selon une loi de Poisson**, qui se fait en quatre étapes :  
1. Initialisation de la graine.  
2. Définition d’un générateur de nombres aléatoires.  
3. Définition de la distribution de Poisson de paramètre \( \lambda[i] \).  
4. Génération d’un nombre selon cette distribution.  

---

#### **4. Classe `Systeme2P`**  
Modélise un **système avec deux personnes**.  
- Hérite de `Système`.  
- Contient deux objets `Personne` représentant les individus en interaction.  
- Implémente `solveSysteme()` pour résoudre le système à deux individus.  
- Gère l’**influence réciproque** entre les individus via les paramètres \( \alpha, \beta, \gamma \).  

---

#### **5. Classe `Graphique`**  
Permet de générer des fichiers **`.csv`** pour tracer des courbes avec **Gnuplot**.  
- Constructeur prenant en paramètre le **nom du fichier CSV** et les **personnes à tracer**.  
- Méthode `Tracer()` : génère un fichier avec les données nécessaires à la visualisation des résultats.  

---

## 3. Compilation et Exécution  

Cloner le dépôt et compiler le programme avec :  

```bash
git clone https://github.com/votre-utilisateur/votre-repo.git
cd votre-repo
g++ -o addiction_model addiction_model.cpp
./addiction_model
```

## Auteur

Ce projet a été réalisé par **ALOUI Ghaieth**, étudiant en **Mathématiques Appliquées et Modélisation** à **POLYTECH Nice Sophia** – **Université Côte d'Azur**, dans le cadre d'un projet C++ (**semestre S7**).
