/*menu update script*/


void main()
{
	if(getglobalvar("menuopen"))
	{
		int selector, selectore, selectorw;
		int textz = 0x10000010;
		if(getglobalvar("menutype")==NULL())
		{
			selector = getglobalvar("selector");
			if(selector==NULL())
			{
				selector=0;
			}
			drawsprite(getglobalvar("menubg"), 0, 0, 0x10000000, 0);
			drawstring(100, 200, (selector==0), "Change Element", textz);
			drawstring(100, 240, (selector==1), "Change Weapon", textz);
		}
		else if(getglobalvar("menutype")=="element")
		{
			selectore = getglobalvar("selectore");
			if(selectore==NULL())
			{
				selectore=0;
			}
			drawsprite(getglobalvar("ebg"), 0, 0, 0x10000000, 0);
			drawstring(300, 120, (selectore==0), "Blaze Gauntlet", textz);
			drawstring(300, 160, (selectore==1), "Windwalker", textz);
			drawstring(300, 200, (selectore==2), "Aurora Ring", textz);
			drawstring(300, 240, (selectore==3), "Force Vest", textz);
			drawstring(300, 280, (selectore==4), "Astra Bracelet", textz);
			drawstring(300, 320, (selectore==5), "Shadow Talisman", textz);
			//drawsprite(getglobalvar("magicicon1"), 40, 40, 0x10000000, 0); //current
			drawsprite(getglobalvar("magicicon"+(selectore+1)), 16, 88, textz, 0);
			drawsprite(getglobalvar("magicdescicon"+(selectore+1)), 526, 88, textz, 0);
		}
		else
		{
			selectorw = getglobalvar("selectorw");
			if(selectorw==NULL())
			{
				selectorw=0;
			}
			drawsprite(getglobalvar("wbg"), 0, 0, 0x10000000, 0);
			drawstring(300, 100, (selectorw==0), "Dagger", textz);
			drawstring(300, 140, (selectorw==1), "Buzzbaton", textz);
			drawstring(300, 180, (selectorw==2), "Fortune Sword", textz);
			drawstring(300, 220, (selectorw==3), "Shiva", textz);
			drawstring(300, 260, (selectorw==4), "Demon Edge", textz);
			drawstring(300, 300, (selectorw==5), "Dual Daggers", textz);
			drawstring(300, 340, (selectorw==6), "Jeweled Knives", textz);
			drawstring(300, 380, (selectorw==7), "Venom Fangs", textz);
			//drawsprite(getglobalvar("weaponicon1"), 40, 40, 0x10000000, 0); //current
			drawsprite(getglobalvar("weaponicon"+(selectorw+1)), 16, 88, textz, 0);
			drawsprite(getglobalvar("weapondescicon"+(selectorw+1)), 526, 88, textz, 0);
		}
	}
}
