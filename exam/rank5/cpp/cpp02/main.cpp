#include "Warlock.hpp"
#include "Polymorph.hpp"
#include "BrickWall.hpp"
#include "TargetGenerator.hpp"
#include "Firewall.hpp"

int main()
{
    Warlock richard("Richard", "foo");
    richard.setTitle("Hello, I'm Richard the Warlock!");
    BrickWall model1;

    Polymorph* polymorph = new Polymorph();
    TargetGenerator tarGen;

    tarGen.learnTargetType(&model1);
    richard.learnSpell(polymorph);

    Firewall* firewall = new Firewall();

    richard.learnSpell(firewall);

    ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

    richard.introduce();
    richard.launchSpell("Polymorph", *wall);
    richard.launchSpell("Firwall", *wall);
    while (1)
    ;   
}
