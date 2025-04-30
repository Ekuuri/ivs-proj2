Epic calculator + program na výpočet směrodatné odchylky stddev
----------------------------------------------------------------
Kalkulačka s vlastní matematickou knihovnou, schopná provádět základní aritmetické operace, výpočet faktoriálu, umocňováním s přirozenými exponenty, obecnou odmocninou a funkci modulo.

Instalace
---------------
Instalaci je možné provést skrze instalační balíčky debian (v případě potřeby bližší popis naleznete v uživatelské dokumentaci), nebo vystavěním programu ze zdrojových souborů:


Nejprve naklonujte repozitář (nebo stáhněte a rozbalte ZIP):
"git clone https://github.com/Ekuuri/ivs-proj2.git"

Poté postupujte následovně:

    Přejděte do zdrojového adresáře:
    "cd ivs-proj2/src"
    Sestavte všechny cíle:
    "make all"
    Pokud kompilace selže, postupujte dle chybových hlášek v terminálu.
    
    V případě, že sestavení proběhlo bez potíží nainstalujte požadovanou komponentu:
        Jen Epic Calculator:
        "cmake --install ../build --component EpicCalc"
        Jen stddev:
        "cmake --install ../build --component stddev"
        Obě komponenty:
        "cmake --install ../build"
Odinstalace
---------------
Skrze příkaz "sudo apt remove" (viz programová dokumentace), nebo skrze uninstaller příkazem: "/opt/epicCalculator/uninstall.sh"

Prostředí
---------

Ubuntu 64bit

Autoři
------

audentes Fortuna iuvat
- xlescet00 Tobias Leščenko
- xjedliv01 Vojtěch Jedlička
- xfurism00 Marek Furiš
- xsrajed00 Dan Šrajer 

Licence
-------

Tento program je poskytován pod licencí GNU General Public License, version 3. Viz níže.

     This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
