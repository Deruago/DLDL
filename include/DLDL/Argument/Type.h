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
	};
}

#endif // DLDL_ARGUMENT_TYPE_H
