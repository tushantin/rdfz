void main()
{
	setglobalvar("msprite", loadsprite("data/sprites/mbg.gif"));
	setglobalvar("s1name", "serge");
	setglobalvar("s2name", "max");
	setglobalvar("s3name", "kid");
	setglobalvar("sec1", 0);
	setglobalvar("sec2", 1);
	setglobalvar("sec3", 0);
	setglobalvar("msel", 1);
	setspawnentry("name", "m_serge");
	setspawnentry("coords", 200, 200);
	setspawnentry("flip", 0);
	setglobalvar("mentity", spawn());
	setspawnentry("name", "mi_serge");
	setspawnentry("coords", 600, 200);
	setspawnentry("flip", 1);
	setglobalvar("mientity", spawn());
}