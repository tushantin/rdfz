void main()
{
        int length = 220;
        setdrawmethod(NULL(), 1, 256*length, 256); // set temporary drawmethod for the sprite
        drawsprite(getglobalvar("lbsprite"), 100, 250, 1000, 0); // draw the sprite at (x, y, z) = (100, 250, 1000)
        setdrawmethod(NULL(), 0, 256, 256); // reset the drawmethod so you can use it for other methods, optional
}