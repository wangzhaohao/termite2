#include "ConcentrationDiffusionTemp.h"

registerMooseObject("Termite2App",ConcentrationDiffusionTemp);

InputParameters
ConcentrationDiffusionTemp::validParams()
{
    InputParameters params = Kernel::validParams();

    params.addRequiredCoupledVar("temp","Coupled temperature");

    return params;
}

ConcentrationDiffusionTemp::ConcentrationDiffusionTemp(const InputParameters & parameters)
    : Kernel(parameters),
    _temp(coupledValue("temp")),
    _second_temp(coupledSecond("temp"))
{
}

Real
ConcentrationDiffusionTemp::computeQpResidual()
{
  /* std::cout<<_second_temp[_qp](0,0)<<std::endl; */
  /* std::cout<<_second_temp[_qp].tr()<<std::endl; */
    return -_test[_i][_qp] * 640 * (_u[_qp] * _second_temp[_qp].tr() / std::pow(_temp[_qp],2));
}
