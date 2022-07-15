#include "ConcentrationConvectionTemp.h"

registerMooseObject("Termite2App",ConcentrationConvectionTemp);

InputParameters
ConcentrationConvectionTemp::validParams()
{
    InputParameters params = Kernel::validParams();

    params.addRequiredCoupledVar("temp","coupled temperature");

    return params;
}

ConcentrationConvectionTemp::ConcentrationConvectionTemp(const InputParameters & parameters)
    : Kernel(parameters),
    _temp(coupledValue("temp")),
    _grad_temp(coupledGradient("temp"))
{
}

Real
ConcentrationConvectionTemp::computeQpResidual()
{
  /* std::cout<<_grad_temp[_qp]<<std::endl; */
    return _test[_i][_qp] * 2 * 640 * (_u[_qp] * _grad_temp[_qp] * _grad_temp[_qp] / std::pow(_temp[_qp],3));
}
