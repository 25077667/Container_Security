sudo docker run -it --rm --env="DISPLAY" \
	--volume="${XAUTHORITY:-${HOME}/.Xauthority}:/root/.Xauthority:ro" \
	--volume="/tmp/.X11-unix:/tmp/.X11-unix" \
	--volume="winehome:/home/wineuser" \
	-v "${pwd}":"/line" \
	--hostname="$(hostname)" wine0 \
	wine LineInst.exe
