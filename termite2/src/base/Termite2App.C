#include "Termite2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
Termite2App::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

Termite2App::Termite2App(InputParameters parameters) : MooseApp(parameters)
{
  Termite2App::registerAll(_factory, _action_factory, _syntax);
}

Termite2App::~Termite2App() {}

void
Termite2App::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"Termite2App"});
  Registry::registerActionsTo(af, {"Termite2App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
Termite2App::registerApps()
{
  registerApp(Termite2App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
Termite2App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Termite2App::registerAll(f, af, s);
}
extern "C" void
Termite2App__registerApps()
{
  Termite2App::registerApps();
}
