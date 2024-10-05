cmake_minimum_required(VERSION 3.14)
project(Modelisation-dun-comportement-addictif)

# Trouver la bibliothèque Matplot++
find_package(Matplot++ REQUIRED)

# Ajouter tous les fichiers source
add_executable(my_target 
    main.cpp 
    Personne.cpp 
    Systeme1P.cpp 
    Systeme2P.cpp 

)

# Lier Matplot++ à l'exécutable
target_link_libraries(my_target PRIVATE Matplot++::matplot)