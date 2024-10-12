#pragma once
namespace MathEngine {

	// Constantes matemáticas
	constexpr float PI = 3.14159265358979323846f;
	constexpr float E = 2.71828182845904523536f;

	/**
	 * @brief Calcula la raíz cuadrada mediante el método Newton-Raphson.
	 * El valor para calcular la raíz cuadrada de la raíz cuadrada calculada.
	*/
	inline float sqrt(float value) {
		if (value < 0) {
			return 0;
		}
		float x = value;
		float y = 1.0f;
		float epsilon = 0.00001f; // Precisión deseada en el calculo.
		while (x - y > epsilon) {
			x = (x + y) / 2.0f;
			y = value / x;
		}
		return x;
	}
};