#pragma once

#include <SFML/Graphics.hpp>
#include <complex>

/* Type to represent a part of a complex number. */
typedef double coord_t;

/* Type for counting Mandelbrot iterations. */
typedef uint16_t count_t;

/* Type of a single coordinate of pixel on image. */
typedef unsigned img_pos_t;


using Complex = std::complex<double>;
using Scaler = std::function<coord_t(img_pos_t)>;

namespace defaults {
    /* Full HD resolution dimensions. */
    constexpr img_pos_t width = 1920;
    constexpr img_pos_t height = 1080;

    /* Iteration limit for a decent image. */
    constexpr count_t maxiterations = 10'00;
}

class Mandelbrot {
    /* Iteration limit after which complex sequence is considered bounded. */
    const count_t maxiterations;

    /* Creates scaling function which transforms integer
     * from [0, length] to double on interval [minval, maxval]. */
    static Scaler makeScaler(coord_t minval, coord_t maxval, img_pos_t length);

    /* Creates a function which transforms a pixel to a scaled complex number. */
    static auto pixelToComplex(const Scaler& realScaler, const Scaler& imagScaler);

    /* Counts amount of Mandelbrot iterations before a possibility of divergence. */
    count_t countIterations(const Complex& c) const;

    /* Maps color to a complex number depending on it's divergence rate. */
    sf::Color complexToColor(const Complex& c) const;

public:
    explicit Mandelbrot(count_t maxiterations) : maxiterations{maxiterations} {}

    Mandelbrot() : Mandelbrot(defaults::maxiterations) {}

    /* Plots the Mandelbrot set over the given image. */
    void plotImage(sf::Image& image) const;
};