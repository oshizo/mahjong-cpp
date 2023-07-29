#include "../../extern/pybind11/include/pybind11/pybind11.h"
#include "../../extern/pybind11/include/pybind11/stl.h"
#include "mahjong/mahjong.hpp"
namespace py = pybind11;
using namespace mahjong;

PYBIND11_MODULE(mahjongpy, m)
{
    m.doc() = "pybind11 example plugin"; // optional module docstring

    // Tile Type
    py::enum_<Tile::Type>(m, "Tile")
        .value("Manzu1", Tile::Type::Manzu1)
        .value("Manzu2", Tile::Type::Manzu2)
        .value("Manzu3", Tile::Type::Manzu3)
        .value("Manzu4", Tile::Type::Manzu4)
        .value("Manzu5", Tile::Type::Manzu5)
        .value("Manzu6", Tile::Type::Manzu6)
        .value("Manzu7", Tile::Type::Manzu7)
        .value("Manzu8", Tile::Type::Manzu8)
        .value("Manzu9", Tile::Type::Manzu9)
        .value("Pinzu1", Tile::Type::Pinzu1)
        .value("Pinzu2", Tile::Type::Pinzu2)
        .value("Pinzu3", Tile::Type::Pinzu3)
        .value("Pinzu4", Tile::Type::Pinzu4)
        .value("Pinzu5", Tile::Type::Pinzu5)
        .value("Pinzu6", Tile::Type::Pinzu6)
        .value("Pinzu7", Tile::Type::Pinzu7)
        .value("Pinzu8", Tile::Type::Pinzu8)
        .value("Pinzu9", Tile::Type::Pinzu9)
        .value("Sozu1", Tile::Type::Sozu1)
        .value("Sozu2", Tile::Type::Sozu2)
        .value("Sozu3", Tile::Type::Sozu3)
        .value("Sozu4", Tile::Type::Sozu4)
        .value("Sozu5", Tile::Type::Sozu5)
        .value("Sozu6", Tile::Type::Sozu6)
        .value("Sozu7", Tile::Type::Sozu7)
        .value("Sozu8", Tile::Type::Sozu8)
        .value("Sozu9", Tile::Type::Sozu9)
        .value("Ton", Tile::Type::Ton)
        .value("Nan", Tile::Type::Nan)
        .value("Sya", Tile::Type::Sya)
        .value("Pe", Tile::Type::Pe)
        .value("Haku", Tile::Type::Haku)
        .value("Hatu", Tile::Type::Hatu)
        .value("Tyun", Tile::Type::Tyun)
        .value("AkaManzu5", Tile::Type::AkaManzu5)
        .value("AkaPinzu5", Tile::Type::AkaPinzu5)
        .value("AkaSozu5", Tile::Type::AkaSozu5)
        .export_values();

    py::class_<Hand>(m, "Hand")
        .def(py::init<>())
        .def(py::init<const std::vector<int> &>(), py::arg("tiles"))
        .def("to_string", &Hand::to_string);

    py::class_<SyantenCalculator>(m, "SyantenCalculator")
        .def_static("calc", &SyantenCalculator::calc, py::arg("hand"), py::arg("type"));


}