
all: items_8x16.png link_16x16.png linkSword_16x16.png sword_16x16.png tileset_16x16.png

clean:
	rm -f items_8x16.png link_16x16.png linkSword_16x16.png sword_16x16.png tileset_16x16.png

items_8x16.png:
	convert -append src/item-*.png -threshold 25% items_8x16.png
	optipng -o7 -strip all -quiet items_8x16.png

link_16x16.png:
	convert -append src/link-*.png -threshold 25% link_16x16.png
	optipng -o7 -strip all -quiet link_16x16.png

linkSword_16x16.png:
	convert -append src/linkSword-*.png -threshold 25% linkSword_16x16.png
	optipng -o7 -strip all -quiet linkSword_16x16.png

sword_16x16.png:
	convert -append src/sword-*.png -threshold 25% sword_16x16.png
	optipng -o7 -strip all -quiet sword_16x16.png

tileset_16x16.png:
	convert -append src/tile-*.png -threshold 25% tileset_16x16.png
	optipng -o7 -strip all -quiet tileset_16x16.png
