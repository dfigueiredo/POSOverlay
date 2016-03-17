#ifndef _PixelSupervisorConfiguration_version_h_
#define _PixelSupervisorConfiguration_version_h_

#include "config/PackageInfo.h"

#define PIXELSUPERVISORCONFIGURATION_VERSION_MAJOR 1
#define PIXELSUPERVISORCONFIGURATION_VERSION_MINOR 0
#define PIXELSUPERVISORCONFIGURATION_VERSION_PATCH 0
#undef PIXELSUPERVISORCONFIGURATION_PREVIOUS_VERSIONS
#define PIXELSUPERVISORCONFIGURATION_VERSION_CODE PACKAGE_VERSION_CODE(PIXELSUPERVISORCONFIGURATION_VERSION_MAJOR, PIXELSUPERVISORCONFIGURATION_VERSION_MINOR, PIXELSUPERVISORCONFIGURATION_VERSION_PATCH)

#ifndef PIXELSUPERVISORCONFIGURATION_PREVIOUS_VERSIONS
#define PIXELSUPERVISORCONFIGURATION_FULL_VERSION_LIST PACKAGE_VERSION_STRING(PIXELSUPERVISORCONFIGURATION_VERSION_MAJOR, PIXELSUPERVISORCONFIGURATION_VERSION_MINOR, PIXELSUPERVISORCONFIGURATION_VERSION_PATCH)
#else
#define PIXELSUPERVISORCONFIGURATION_FULL_VERSION_LIST PIXELSUPERVISORCONFIGURATION_PREVIOUS_VERSIONS "," PACKAGE_VERSION_STRING(PIXELSUPERVISORCONFIGURATION_VERSION_MAJOR, PIXELSUPERVISORCONFIGURATION_VERSION_MINOR, PIXELSUPERVISORCONFIGURATION_VERSION_PATCH)
#endif

namespace PixelSupervisorConfiguration {
  
  const std::string package = "PixelSupervisorConfiguration";
  const std::string versions = PIXELSUPERVISORCONFIGURATION_FULL_VERSION_LIST;
  const std::string summary = "PixelSupervisorConfiguration";
  const std::string description = "PixelSupervisorConfiguration XDAQ application";
  const std::string authors = "POS team";
  const std::string link = "http://xdaq.web.cern.ch";
  
  config::PackageInfo getPackageInfo();
  void checkPackageDependencies() throw (config::PackageInfo::VersionException);
  std::set<std::string, std::less<std::string> > getPackageDependencies();
  
}

#endif