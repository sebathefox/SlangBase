/**
 * The file containing the file implementation.
 * @file File.h
 * @author Sebastian Davaris
 * @date 24-09-2019
 */

#ifndef SLANGBASE_FILE_H
#define SLANGBASE_FILE_H

#include <string>
#include <fstream>
/**
 * Til alle dem, der vender verden på hoved
 * Op op op op
 * Når du går rundt i din by og bliver lidt trist over nybyggerriet
 * Sikker tegnet nogen for hvem det heller ikke rigtigt sagde en skid
 * Når du træder på asfalt, der er så varmt at du synker i
 * Og du banker på, på en anstalt og de spørger hvorfor, og du svarer fordi.
 * Skrig det til træerne
 * åh til træerne
 * og gi det alt, men gi ikke op op op
 * Skrig det dog til træerne
 * Spil sinssyg på klavererne
 * Når du bare åbner op, og hælder dit hjerte ud i et net
 * Gennemhullet af tanker, om hvad man kan bliver, du bliver så træt
 * Og du banker dig selv og tror det er dig, der har misforstået
 * Du kan ikke længere føle, hvordan det er at føle noget for noget
 * Skrig det til træerne
 * Hvis du går rundt i din by obg blir lidt trist over nybyggerriet
 * åh til træerne
 * åh du banker løs på dig selv og siger du må ha misforstået
 * gi det alt, men gi ikke op op op
 * skrig det dog til træerne
 * spil sinssyg på klavererne
 * Hør her før den her sang den går ud:
 * gi ikke op op op
 * Til alle den, der vender verden på hovedt
 * gi ikke op op op
 * Så kom her, jeg syns vi nærmer os noget
 * som er langt væk, for det vi troede vi forstod
 * gi ikke op!
 * skrig det til træerne
 * Når du går rundt i din by, og blir lidt trist over nybyggeri
 * åh til træerne
 * åh hvis du bare banker løs på mig selv, og tænker du må ha misforstået
 * Hør her før den her sang den går ud
 * åh til træerne
 * Hvis du mærker noget, så gå lidt væk fra alt hvad du troede
 * Spil sinssyg på klavererne
 */
namespace io {
    /**
     * The file struct that holds the neccessary file info to read and write a file.
     * @author Sebastian Davaris
     * @date 24-09-2019
     */
    class File {
    public:
        std::string m_name;
        std::fstream m_file;

        /**
         * Creates a new File object.
         * @author Sebastian Davaris
         * @date 25-09-2019
         * @param fileName The file to open.
         */
        explicit File(std::string fileName);

        /**
         * Removes the object from memory.
         * @author Sebastian Davaris
         * @date 25-09-2019
         */
        ~File();

        /**
         * Sets the text in the file to the text value.
         * @author Sebastian Davaris
         * @date 25-09-2019
         * @param text The text to write to the file.
         */
        void SetText(std::string text);
    };
}

#endif //SLANGBASE_FILE_H
