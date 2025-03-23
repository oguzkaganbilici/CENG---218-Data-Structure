//
// Created by Oğuz Kağan Bilici on 23.03.2025.
//

#include "Scooter.h"

Scooter::Scooter(int id, string loc, int stats, int battery, int distance, string data): next(nullptr), id(id), location(loc), status(stats), battery_level(battery), distance(distance), last_usage_date(data) {};