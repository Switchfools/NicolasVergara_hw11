pos.png : NV_graph.py tray.txt
	python3 NV_graph.py
tray.txt : gravity
	./gravity>tray.txt
gravity :NV_gravity.cpp
	c++ NV_gravity.cpp -o gravity
