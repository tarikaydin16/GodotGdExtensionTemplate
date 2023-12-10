extends Node2D


# Called when the node enters the scene tree for the first time.
func _ready():
	$HelloWorld.hello_world("hello from gd script")


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass


func _on_hello_world_hello_world_signal(data):
	print("emitted signal "+data)
