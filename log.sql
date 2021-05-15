-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports WHERE street = "Chamberlin Street";

SELECT * FROM interviews WHERE transcript LIKE "%courthouse%" AND year = 2020 AND month = 7 AND day = 28;

--chamberlin street, July 28th 2020


SELECT activity, license_plate, year, month, day, hour, minute FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10;

SELECT * FROM people WHERE license_plate = "5P2BI95" OR license_plate = "94KL13X"
OR license_plate = "6P58WS2" OR license_plate = "4328GD8" OR license_plate = "G412CB7" OR license_plate = "L93JTIZ" OR license_plate = "322W7JE"
OR license_plate = "0NTHK55" OR license_plate = "1106N58";
SELECT * FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60) ORDER BY id ASC;
SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60) ORDER BY id ASC;
SELECT * FROM people WHERE phone_number = "(375) 555-8161";
suspects: madison, ernest, evelyn


SELECT name, id FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28 and atm_location = "Fifer Street"));

SELECT * FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id
IN (SELECT id from flights WHERE year = 2020 AND month = 7 AND day = 29 AND hour = 8 AND minute = 20)));


SELECT city FROM airports WHERE id IN
(SELECT destination_airport_id FROM flights WHERE year = 2020 AND month = 7 AND day = 29 AND hour = 8 AND minute = 20);
