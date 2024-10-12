#pragma once
#include "MathEngine.h"

class Vector2 {
public:

    // Valores de las coordenadas x y y
    float x;
    float y;

    /**
     * @brief Constructor por defecto
     * Inicializa las coordenadas del los vectores desde 0
    */
    Vector2() : x(0), y(0) {}

    /**
     * @brief Constructor parametrizado.
     * Inicializa las coordenadas de los vectores de los valores dados.
    */
    Vector2(float xVal, float yVal) : x(xVal), y(yVal) {}

    // Sobrecarga del operador para la suma de 2 vectores.
    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    // Sobrecarga del operador para la resta de 2 vectores.
    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    // Sobrecarga del operador para la multiplicación de 2 vectores.
    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    /**
     * @brief Calcula la magnitud del vector.
     * La magnitud se calcula como la raíz cuadrada de la suma de los cuadrados de sus componentes.
     * Se calcular la raíz cuadrada a través de MathEngine.h.
    */
    float magnitude() const {
        return MathEngine::sqrt(x * x + y * y);
    }

    /**
     * @brief Método para normalizar el vector.
     * Devuelve un vector en la misma dirección pero con magnitud 1.
     * Si el vector tiene magnitud 0, devuelve un vector con componentes (0, 0).
    */
    Vector2 normalize() const {
        float mag = magnitude();
        if (mag == 0) {
            return Vector2(0, 0);
        }
        return Vector2(x / mag, y / mag);
    }

    // Método para devolver un puntero a los datos no constantes.
    float* data() {
        return &x;
    }

    // Método para devolver un puntero a los datos constantes.
    const float* 
    data() const {
        return &x;
    }
};