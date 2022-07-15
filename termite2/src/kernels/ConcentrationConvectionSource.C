#include "ConcentrationConvectionSource.h"

registerMooseObject("Termite2App",ConcentrationConvectionSource);

InputParameters
ConcentrationConvectionSource::validParams()
{
  InputParameters params = Kernel::validParams();
  params.addRequiredCoupledVar("temp","coupled temperature");
  
  return params;
}

ConcentrationConvectionSource::ConcentrationConvectionSource(const InputParameters & parameters)
  : Kernel(parameters),
  _temp(coupledValue("temp")),
  _grad_temp(coupledGradient("temp"))
{
}

Real
ConcentrationConvectionSource::computeQpResidual()
{
  return _grad_test[_i][_qp] * 640 * _u[_qp] * _grad_temp[_qp] / std::pow(_temp[_qp],2);
}
