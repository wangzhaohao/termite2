#include "ConcentrationConvection.h"

registerMooseObject("Termite2App", ConcentrationConvection);

InputParameters
ConcentrationConvection::validParams()
{
    InputParameters params = Kernel::validParams();

    params.addRequiredCoupledVar("temp","Coupled temp");

    return params;
}

ConcentrationConvection::ConcentrationConvection(const InputParameters & parameters)
    : Kernel(parameters),
    _temp(coupledValue("temp")),
    _grad_temp(coupledGradient("temp"))
{
}

Real
ConcentrationConvection::computeQpResidual()
{
    return -_test[_i][_qp] * 640 * (_grad_u[_qp] * _grad_temp[_qp] / std::pow(_temp[_qp],2));
}
