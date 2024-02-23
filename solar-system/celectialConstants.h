#ifndef CELECTIAL_CONSTANTS_H
#define CELECTIAL_CONSTANTS_H


/* SCREEN CONSTANTS */
const float SCR_WIDTH{ 1700.f };
const float SCR_HEIGHT{ 800.f };
const float OFFSET{ 6.f };    // add or substract OFFSET to make planet sizes less ridicilous



/* CELESTIAL BODIES' PROPERTIES */
// Astronomical Unit (AU - distance from Sun to Earth)
const float AU{ 20.f };

// PI number
const float M_PI{ 3.141592f };

// Radii
const float R_SUN{ 90.f };   // Sun
const float R_JUP{ 10.f };   // Jupiter
const float R_SAT{ 8.3f };   // Saturn
const float R_URA{ 3.65f };  // Uranus
const float R_NEP{ 3.54f };  // Neptune
const float R_EAR{ .92f };   // Earth
const float R_VEN{ .87f };   // Venus
const float R_MAR{ .49f };   // Mars
const float R_MER{ .35f };   // Mercury

// Distance in AU (AU above)
const float dSUN{ 0.f };
const float dJUP{ 5.203f };
const float dSAT{ 9.54f };
const float dURA{ 19.2f };
const float dNEP{ 30.06f };
const float dEAR{ 1.f };
const float dVEN{ 0.72f };
const float dMAR{ 1.524f };
const float dMER{ 0.39f };

// Colors
const sf::Color sunColor{ 0xFFFF00FF };
const sf::Color jupColor{ 0xC1844DFF };
const sf::Color satColor{ 0x733D1AFF };
const sf::Color uraColor{ 0x78DEFCFF };
const sf::Color nepColor{ 0x537CFEFF };
const sf::Color earColor{ 0x417B38FF };
const sf::Color venColor{ 0xFDFDFDFF };
const sf::Color marColor{ 0x4C0B03FF };
const sf::Color merColor{ 0xE9E802FF };

// Vectors of known data
const std::vector<float>     planetRadii	{ R_SUN, R_JUP, R_SAT, R_URA, R_NEP, R_EAR, R_VEN, R_MAR, R_MER };
const std::vector<float>     planetDist		{ dSUN, dJUP, dSAT, dURA, dNEP, dEAR, dVEN, dMAR, dMER };
const std::vector<sf::Color> planetColors	{ sunColor, jupColor, satColor, uraColor, nepColor, earColor, venColor, marColor, merColor };

#endif
