#include "HareApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

#include "LaplaceYoung.h"

template<>
InputParameters validParams<HareApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

HareApp::HareApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  HareApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  HareApp::associateSyntax(_syntax, _action_factory);
}

HareApp::~HareApp()
{
}

//register kernel LaplaceYoung 
//void
//HareApp::registerObjects(Factory & factory)
//{
//	registerKernel(LaplaceYoung);
//}


// External entry point for dynamic application loading
extern "C" void HareApp__registerApps() { HareApp::registerApps(); }
void
HareApp::registerApps()
{
  registerApp(HareApp);
}

// External entry point for dynamic object registration
extern "C" void HareApp__registerObjects(Factory & factory) { HareApp::registerObjects(factory); }
void
HareApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void HareApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { HareApp::associateSyntax(syntax, action_factory); }
void
HareApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
