
// Includes ====================================================================
#include <boost/python.hpp>
#include <gmtl/Vec.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_Vec_float_4()
{
    scope* gmtl_Vec_float_4_scope = new scope(
    class_< gmtl::Vec<float,4>, bases< gmtl::VecBase<float,4> > >("Vec4f", init<  >())
        .def(init< const gmtl::Vec<float,4> & >())
        .def(init< const gmtl::VecBase<float,4> & >())
        .def(init< const float &, const float & >())
        .def(init< const float &, const float &, const float & >())
        .def(init< const float &, const float &, const float &, const float & >())
    );

    enum_< gmtl::Vec<float,4>::Params >("Params")
        .value("Size", gmtl::Vec<float,4>::Size)
    ;

    delete gmtl_Vec_float_4_scope;

}