
/*start in-game menu*/

void setweapon(int w)
{
}

void setelement(int e)
{
}

void closemenu()
{
	void pauser = getglobalvar("pauser");
	setglobalvar("menuopen", NULL());
	if(pauser)
	{
		killentity(pauser);
		setglobalvar("pauser", NULL());
	}
}

void main()
{
	int p = getlocalvar("player");
	int selector, maxselectors=2;
	int selectore, maxselectores=6;
	int selectorw, maxselectorws=8;
	char menutype;
	if(playerkeys(p, 1, "attack4"))
	{
		if(getglobalvar("menuopen"))// change the flag for update script to do menu logic
		{
			closemenu();
			return;
		}
		else
		{
			setglobalvar("menuopen", 1);
			setspawnentry("name", "Pauser");
			setglobalvar("pauser", spawn());
		}
	}
	if(getglobalvar("menuopen"))
	{
		menutype = getglobalvar("menutype");
		if(menutype==NULL())
		{
			selector = getglobalvar("selector");
			if(selector==NULL())
			{
				selector=0;
			}
			if(playerkeys(p, 1, "movedown"))
			{
				selector++;
				if(selector>=maxselectors)
				{
					selector=0;
				}
			}
			else if(playerkeys(p, 1, "moveup"))
			{
				selector--;
				if(selector<0)
				{
					selector=maxselectors-1;
				}
			}
			else if(playerkeys(p, 1, "attack"))
			{
				if(selector==0)
				{
					menutype = "element";
				}
				else if(selector==1)
				{
					menutype = "weapon";
				}
			}
			setglobalvar("selector", selector);
			setglobalvar("menutype", menutype);
		}
		else if(menutype=="element")
		{
			selectore = getglobalvar("selectore");
			if(selectore==NULL())
			{
				selectore=0;
			}
			if(playerkeys(p, 1, "movedown"))
			{
				selectore++;
				if(selectore>=maxselectores)
				{
					selectore=0;
				}
			}
			else if(playerkeys(p, 1, "moveup"))
			{
				selectore--;
				if(selectore<0)
				{
					selectore=maxselectores-1;
				}
			}
			else if(playerkeys(p, 1, "attack"))
			{
				setelement(selectore);
			}
			else if(playerkeys(p, 1, "jump"))
			{
				menutype = NULL();
			}
			setglobalvar("selectore", selectore);
			setglobalvar("menutype", menutype);
		}
		else if(menutype=="weapon")
		{
			selectorw = getglobalvar("selectorw");
			if(selectorw==NULL())
			{
				selectorw=0;
			}
			if(playerkeys(p, 1, "movedown"))
			{
				selectorw++;
				if(selectorw>=maxselectorws)
				{
					selectorw=0;
				}
			}
			else if(playerkeys(p, 1, "moveup"))
			{
				selectorw--;
				if(selectorw<0)
				{
					selectorw=maxselectorws-1;
				}
			}
			else if(playerkeys(p, 1, "attack"))
			{
				setweapon(selectorw);
			}
			else if(playerkeys(p, 1, "jump"))
			{
				menutype = NULL();
			}
			setglobalvar("selectorw", selectorw);
			setglobalvar("menutype", menutype);
		}
	}
}
