#ifndef DLDL_ARGUMENT_TYPE_H
#define DLDL_ARGUMENT_TYPE_H

namespace DLDL::argument
{
	enum class Type
	{
		unknown,

		initialize,
		language_name,
		generate,
		version,
		license,
		copyright,
		help,
		auto_compile,
		auto_run,
		profile,
		echo,
		debug_dldl,
		debug_build,
		log,
		exit,
		information,
		target_language,
		definition_map,
		build_map,
		print_parse_result,
		compatible,
		supported_grammars,
		about,
		target_os,

		multi_project,
		single_project,

		git_initialize,

		custom_project,
		regenerate,
		lpd_map,
		tool_map,
		deamer_map,
		no_deamer,
		include_dldls,
		activate_lpd_generation,
		activate_tool_generation,
		generate_lpd,
		generate_tool,
		init_lpd,
		init_tool,
		lpd_name,
		tool_name,

		// lpd generation output directories
		lpd_generation_map_main_lpd_include,
		lpd_generation_map_tool_lpd_include,
		lpd_generation_map_main_ldo_include,
		lpd_generation_map_tool_ldo_include,
		lpd_generation_map_main_lpd_source,
		lpd_generation_map_tool_lpd_source,
		lpd_generation_map_main_ldo_source,
		lpd_generation_map_tool_ldo_source,
		lpd_generation_map_main_generator,
		lpd_generation_map_special_generator,
		lpd_generation_map_tool_generator,
		lpd_generation_map_lpd_enumerations,
		lpd_generation_map_ldo_enumerations,
		lpd_generation_map_convertor,
		lpd_generation_map_validator,

		activate_language_generation,

		no_console,
		console_debug_mode,

		default_value_compiler_generator,

		cmake_output_use_legacy_names,
	};
}

#endif // DLDL_ARGUMENT_TYPE_H
