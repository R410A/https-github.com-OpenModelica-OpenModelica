#pragma once
/** @addtogroup coreSystem
 *
 *  @{
 */

#if defined(__vxworks) || defined(__TRICORE__) || defined(RUNTIME_STATIC_LINKING)
  #define BOOST_EXTENSION_LOGGER_DECL
  #define BOOST_EXTENSION_SYSTEM_DECL
  #define BOOST_EXTENSION_EVENTHANDLING_DECL
  #define BOOST_EXTENSION_ALGLOOPDEFAULTIMPL_DECL
  #define BOOST_EXTENSION_SIMVARS_DECL
  #define BOOST_EXTENSION_XML_READER_DECL
#define BOOST_EXTENSION_SIMOBJECTS_DECL 
#define BOOST_EXTENSION_EXTENDEDSYSTEM_DECL 
#define   BOOST_EXTENSION_EXTENDED_SIMVARS_DECL 
#elif defined(OMC_BUILD) || defined(SIMSTER_BUILD)
  #define BOOST_EXTENSION_LOGGER_DECL BOOST_EXTENSION_IMPORT_DECL
  #define BOOST_EXTENSION_SYSTEM_DECL BOOST_EXTENSION_EXPORT_DECL
  #define BOOST_EXTENSION_EXTENDEDSYSTEM_DECL BOOST_EXTENSION_EXPORT_DECL
  #define BOOST_EXTENSION_SIMOBJECTS_DECL BOOST_EXTENSION_EXPORT_DECL
  #define BOOST_EXTENSION_EVENTHANDLING_DECL BOOST_EXTENSION_EXPORT_DECL
  #define BOOST_EXTENSION_ALGLOOPDEFAULTIMPL_DECL BOOST_EXTENSION_EXPORT_DECL
  #define BOOST_EXTENSION_SIMVARS_DECL BOOST_EXTENSION_EXPORT_DECL
  #define   BOOST_EXTENSION_EXTENDED_SIMVARS_DECL BOOST_EXTENSION_EXPORT_DECL
  #define BOOST_EXTENSION_XML_READER_DECL BOOST_EXTENSION_IMPORT_DECL
#else
error
"operating system not supported"
#endif

/** @} */ // end of coreSystem