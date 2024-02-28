#pragma once

// Event types are coupled to the current game
// I could replace this with strings but then there would be higher likelyhood of typos
enum EventType {
	THRUST,
	REVERSE,
	TURN_LEFT,
	TURN_RIGHT
};