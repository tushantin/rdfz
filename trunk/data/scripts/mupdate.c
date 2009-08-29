void updatebg()
{
	void spr = getglobalvar("msprite");
	int bgy = getglobalvar("mbgy");
	if(bgy==NULL()) 
	{
		bgy=0;
	}
	bgy++;
	if(bgy>480)
	{
		bgy-=480;
	}
	setglobalvar("mbgy", bgy);
	drawsprite(spr, 0, bgy, 0x10000000, 0);
	drawsprite(spr, 0, bgy-480, 0x10000000, 0);
}

void main()
{
	updatebg();

	int msel = getglobalvar("msel");
	int sec, newk=0;
	if(playerkeys(0, 1, "moveright"))
	{
		msel++;
		if(msel>3)
		{
			msel=1;
		}
		newk=1;
	}
	if(playerkeys(0, 1, "moveleft"))
	{
		msel--;
		if(msel<1)
		{
			msel=3;
		}
		newk=1;
	}
	sec = getglobalvar("sec"+msel);
	if(playerkeys(0, 1, "attack"))
	{
		if(!sec)
		{
			changeplayerproperty(0, "name", getglobalvar("s"+msel+"name"));
			jumptobranch("start", 1);
			return;
		}
	}
	if(newk)
	{
		killentity(getglobalvar("mentity"));
		killentity(getglobalvar("mientity"));
		if(sec)
		{
			setspawnentry("name", "m_dummy");
		}
		else
		{
			setspawnentry("name", "m_"+getglobalvar("s"+msel+"name"));
		}
		setspawnentry("coords", 200, 200);
		setspawnentry("flip", 0);
		setglobalvar("mentity", spawn());
		if(!sec)
		{
			setspawnentry("name", "mi_"+getglobalvar("s"+msel+"name"));
			setspawnentry("coords", 600, 200);
			setspawnentry("flip", 1);
			setglobalvar("mientity", spawn());
		}
	}
	setglobalvar("msel", msel);
}