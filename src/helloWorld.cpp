#include "helloWorld.h"
#include <class_db.hpp>
// #include <godot_cpp/godot.hpp>
#include <utility_functions.hpp>
#include <engine.hpp>
#include <input.hpp>
using namespace godot;

void HelloWorld::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("get_speed"), &HelloWorld::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), &HelloWorld::set_speed);
    ClassDB::bind_method(D_METHOD("hello_world", "words"), &HelloWorld::hello_world);
    ClassDB::add_property("HelloWorld", PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

    ADD_SIGNAL(MethodInfo("hello_world_signal", PropertyInfo(Variant::STRING, "data")));
}

HelloWorld::HelloWorld()
{
    if (Engine::get_singleton()->is_editor_hint())
    {
        set_process_mode(Node::ProcessMode::PROCESS_MODE_DISABLED);
    }
    UtilityFunctions::print("hello world!");
}
HelloWorld::~HelloWorld()
{
}
void HelloWorld::hello_world(String words)
{
    UtilityFunctions::print("Hello world! " + words);
    emit_signal("hello_world_signal", "data!");
}

void HelloWorld::_process(double delta)
{
    UtilityFunctions::print("hello from process!");
    velocity = Vector2(0.0f, 0.0f);
    Input &inputSingleton = *Input::get_singleton();
    if (inputSingleton.is_action_pressed("d"))
    {
        velocity.x += 1.0f;
    }
    if (inputSingleton.is_action_pressed("a"))
    {
        velocity.x -= 1.0f;
    }
    if (inputSingleton.is_action_pressed("w"))
    {
        velocity.y -= 1.0f;
    }
    if (inputSingleton.is_action_pressed("s"))
    {
        velocity.y += 1.0f;
    }

    set_position(get_position() + (velocity * speed * delta));
}

void HelloWorld::set_speed(const double _speed)
{
    speed = _speed;
}
double HelloWorld::get_speed() const
{
    return speed;
}