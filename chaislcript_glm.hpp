#pragma once

#include <glm/glm.hpp>
#include <chaiscript/chaiscript.hpp>

static chaiscript::ModulePtr get_glm_module()
{
	chaiscript::ModulePtr glm_module = chaiscript::ModulePtr(new chaiscript::Module);
	glm_module->add(chaiscript::user_type<glm::vec3>(), "vec3");
	glm_module->add(chaiscript::constructor<glm::vec3(float)>(), "vec3");
	glm_module->add(chaiscript::constructor<glm::vec3(float, float, float)>(), "vec3");
	glm_module->add(chaiscript::constructor<glm::vec3(const glm::vec3&)>(), "vec3");
	glm_module->add(chaiscript::constructor<glm::vec3()>(), "vec3");
	glm_module->add(chaiscript::fun(&glm::vec3::x), "x");
	glm_module->add(chaiscript::fun(&glm::vec3::y), "y");
	glm_module->add(chaiscript::fun(&glm::vec3::z), "z");
	glm_module->add(chaiscript::fun(static_cast<glm::vec3(*)(const glm::vec3&, const glm::vec3&)>(glm::operator+)), "+");
	glm_module->add(chaiscript::fun(static_cast<glm::vec3(*)(const glm::vec3&, const glm::vec3&)>(glm::operator-)), "-");
	glm_module->add(chaiscript::fun(static_cast<glm::vec3(*)(const glm::vec3&)>(glm::operator-)), "-");
	glm_module->add(chaiscript::fun(static_cast<glm::vec3(*)(const glm::vec3&, const glm::vec3&)>(glm::operator*)), "*");
	glm_module->add(chaiscript::fun(static_cast<glm::vec3(*)(float, const glm::vec3&)>(glm::operator*)), "*");
	glm_module->add(chaiscript::fun(static_cast<glm::vec3(*)(const glm::vec3&, float)>(glm::operator*)), "*");
	glm_module->add(chaiscript::fun(static_cast<glm::vec3(*)(const glm::vec3&)>(glm::normalize)), "normalize");
	glm_module->add(chaiscript::fun(static_cast<glm::vec3(*)(const glm::vec3&, const glm::vec3&)>(glm::cross)), "cross");
	glm_module->add(chaiscript::fun(static_cast<glm::vec3(*)(const glm::vec3&, const glm::vec3&)>(glm::reflect)), "reflect");
	glm_module->add(chaiscript::fun(static_cast<float(*)(const glm::vec3&)>(glm::length)), "length");
	glm_module->add(chaiscript::fun(static_cast<float(*)(const glm::vec3&, const glm::vec3&)>(glm::dot)), "dot");
	glm_module->add(chaiscript::fun(static_cast<float(*)(const glm::vec3&, const glm::vec3&)>(glm::distance)), "distance");
	glm_module->add(chaiscript::fun(static_cast<glm::vec3(*)(const glm::vec3&, const glm::vec3&, float)>(glm::refract)), "refract");

	
	glm_module->add(chaiscript::fun([](const glm::vec3& v) -> std::string { return "vec3(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ", " + std::to_string(v.z) + ")"; }), "to_string");

	return glm_module;
}
