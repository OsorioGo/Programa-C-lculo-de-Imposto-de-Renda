EINKOMMENSTEUER-BERECHNUNGSPROGRAMM


Das folgende Programm wurde als Abschlussprojekt für den Kurs Strukturierte Programmierung in C an der Fatec entwickelt.

Das Projekt verwendet mehrere Konzepte der Programmiersprache C, darunter:

* Code-Modularisierung
* Strukturen (struct)
* Dateiverarbeitung
* Schleifenstrukturen
* Bedingte Anweisungen
* String- und Array-Manipulation
* Komplexe mathematische Berechnungen



Das Programm basiert auf zwei Hauptfunktionen:


1. Benutzerregistrierung


Ermöglicht es, die Daten einer Person in der Datei BD_PF.dat zu speichern.
Die Informationen werden während der Programmausführung vom Benutzer eingegeben.

Bevor ein neuer Datensatz gespeichert wird, überprüft das Programm, ob die angegebene Steuer-ID bereits in der Datei existiert.
Falls die Steuer-ID bereits registriert ist, zeigt das Programm eine Fehlermeldung an und bricht den Vorgang ab.





2. Einkommensteuerberechnung


Dieser Befehl berechnet die Einkommensteuer auf Grundlage der zuvor in der Datei gespeicherten Daten.

Das Programm fordert die Steuer-ID des Steuerpflichtigen an, sucht den entsprechenden Datensatz in der Datei und führt anschließend die Steuerberechnung durch.





Berechnungsmethode


Die Einkommensteuer wird nach folgender Formel berechnet:
Einkommensteuer = Grundgehalt * Steuersatz


Das Grundgehalt wird wie folgt berechnet:
Gesamtes Jahreseinkommen – Gesamte jährliche Abzüge


Der Steuersatz wird gemäß der folgenden Tabelle festgelegt:


* 0 – 21453.24		   0%
* 21453.25 – 32151.48	 7.5%
* 32151.49 – 42869.16	15.0%
* 42869.17 – 53565.72	22.5%
* Above 53565.73	27.5%



👉 Hinweis: Die Benutzeroberfläche und die Ausgaben des Programms sind ausschließlich auf Portugiesisch verfügbar 🇧🇷
