#pragma once
#include "MathEngine.h"
#include "Vector3.h"

class Quaternion {
public:

    //Partes vectoriales (x, y, z y w) del cuaternión.
    float w, x, y, z;

    /**
     * @brief Constructor por defecto.
     * Inicializa las componentes del cuaternión a (0, 0, 0, 0).
     */
    Quaternion() : w(0), x(0), y(0), z(0) {}

    /**
     * @brief Constructor parametrizado.
     * Inicializa las componentes del cuaternión con los valores especificados.
     */
    Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

    /**
     * @brief Constructor que inicializa un cuaternión a partir de un ángulo y un eje de rotación.
     * Este constructor genera un cuaternión que representa una rotación en 3D dada por un
     * ángulo (en radianes) y un eje de rotación.
     */
    Quaternion(float angle, const Vector3& axis) {
        float halfAngle = angle / 2.0f;
        float sinHalfAngle = MathEngine::sin(halfAngle);
        w = MathEngine::cos(halfAngle);
        x = axis.x * sinHalfAngle;
        y = axis.y * sinHalfAngle;
        z = axis.z * sinHalfAngle;
    }

    // Sobrecarga del operador + para sumar 2 cuaterniones.
    Quaternion operator+(const Quaternion& other) const {
        return Quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
    }

    // Sobrecarga del operador + para restar 2 cuaterniones.
    Quaternion operator-(const Quaternion& other) const {
        return Quaternion(w - other.w, x - other.x, y - other.y, z - other.z);
    }

    // Sobrecarga del operador * para multiplicar un cuaternión por un escalar.
    Quaternion operator*(float scalar) const {
        return Quaternion(w * scalar, x * scalar, y * scalar, z * scalar);
    }

    //Sobrecarga del operador * para multiplicar dos cuaterniones.
    Quaternion operator*(const Quaternion& other) const {
        return Quaternion(
            w * other.w - x * other.x - y * other.y - z * other.z,
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w
        );
    }

    /**
     * @brief Calcula la magnitud del cuaternión.
     * La magnitud de un cuaternión se calcula como la raíz cuadrada de la suma de los cuadrados de sus componentes.
     * Se calcular la raíz cuadrada a través de MathEngine.h.
     */
    float magnitude() const {
        return MathEngine::sqrt(w * w + x * x + y * y + z * z);
    }

    /**
     * @brief Normaliza el cuaternión.
     * Devuelve un cuaternión con la misma dirección, pero con magnitud 1.
     * Si la magnitud es 0, devuelve un cuaternión nulo.
     */
    Quaternion normalize() const {
        float mag = magnitude();
        if (mag == 0) {
            return Quaternion(0, 0, 0, 0);
        }
        return Quaternion(w / mag, x / mag, y / mag, z / mag);
    }

    /**
     * @brief Calcula el conjugado del cuaternión.
     * El conjugado de un cuaternión se obtiene invirtiendo el signo de su parte vectorial.
     */
    Quaternion conjugate() const {
        return Quaternion(w, -x, -y, -z);
    }

    /**
     * @brief Calcula el inverso del cuaternión.
     * El inverso de un cuaternión se define como su conjugado dividido entre su magnitud al cuadrado.
     */
    Quaternion inverse() const {
        float magSquared = w * w + x * x + y * y + z * z;
        if (magSquared == 0) {
            return Quaternion(0, 0, 0, 0);
        }
        return conjugate() * (1.0f / magSquared);
    }

    /**
     * @brief Rota un vector utilizando el cuaternión.
     * Este método rota un vector en el espacio 3D utilizando el cuaternión como rotación.
     */
    Vector3 rotate(const Vector3& v) const {
        Quaternion qv(0, v.x, v.y, v.z);
        Quaternion result = (*this) * qv * this->inverse();
        return Vector3(result.x, result.y, result.z);
    }

    // Devuelve un puntero no constante a los datos del cuaternión.
    float* data() {
        return &w;
    }


    // Devuelve un puntero constante a los datos del cuaternión.
    const float* data() const {
        return &w;
    }
};

