-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports WHERE street = "Chamberlin Street";

SELECT * FROM interviews WHERE transcript LIKE "%courthouse%" AND year = 2020 AND month = 7 AND day = 28;

--chamberlin street, July 28th 2020


SELECT activity, license_plate, year, month, day, hour, minute FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10;

SELECT * FROM people WHERE license_plate = "5P2BI95" OR license_plate = "94KL13X"
OR license_plate = "6P58WS2" OR license_plate = "4328GD8" OR license_plate = "G412CB7" OR license_plate = "L93JTIZ" OR license_plate = "322W7JE" 
OR license_plate = "0NTHK55" OR license_plate = "1106N58";
SELECT * FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60 AND caller = "(286) 555-6063";




