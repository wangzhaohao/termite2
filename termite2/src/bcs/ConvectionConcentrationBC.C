#include "ConvectionConcentrationBC.h"

registerMooseObject("Termite2App",ConvectionConcentrationBC);

InputParameters
ConvectionConcentrationBC::validParams()
{
  InputParameters params = IntegratedBC::validParams();

  params.addRequiredCoupledVar("temp","coupled temperature");

  return params;
}

ConvectionConcentrationBC::ConvectionConcentrationBC(const InputParameters & parameters)
  : IntegratedBC(parameters),
  _temp(coupledValue("temp")),
  _grad_temp(coupledGradient("temp"))
{
}

Real
ConvectionConcentrationBC::computeQpResidual()
{
  std::cout<<_grad_temp[_qp]<<_temp[_qp]<<std::endl;
  return -_test[_i][_qp] * (_u[_qp] * _grad_temp[_qp] / _temp[_qp] / _temp[_qp]) * _normals[_qp];
}
