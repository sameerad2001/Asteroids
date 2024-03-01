#pragma once

// Event types are coupled to the current game
// I could replace this with strings to decouple event types from the game...
// but then there would be a higher likelyhood of typos
enum EventType {
	THRUST,
	REVERSE, // NOT required, buts its there if needed in the future
	TURN_LEFT,
	TURN_RIGHT,
	FIRE,
	PLAYER_ASTEROID_COLLISION,
	BULLET_ASTEROID_COLLISION,
	GAME_START
};