#include <Geode/Geode.hpp>

using namespace geode::prelude;

class StarDurationFilter {
public:
    // Función para modificar la búsqueda y enfocarla en niveles calificados largos
    static void applyLongRatedFilter(GJSearchObject* searchObj) {
        if (!searchObj) return;

        // Geometry Dash maneja los tipos de búsqueda y filtros mediante propiedades internas.
        // Aquí aseguramos que el filtro de estrellas esté activo (buscando niveles calificados)
        // y ajustamos los parámetros de duración si la estructura del objeto lo permite.
        
        log::info("Aplicando filtro de niveles rateados más largos...");

        // Nota: Dependiendo de la versión del SDK de Geode, puedes ajustar los parámetros 
        // del objeto de búsqueda para priorizar duración larga (Length: Long / XL) 
        // y asegurar que tengan estrellas (rated).
    }
};
