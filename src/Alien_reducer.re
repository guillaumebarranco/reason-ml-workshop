let alienSpeed = 0.3;

let nextX = (elapsedTime: float, a: Types.alien) : float => 0.;

let isOnEdge = (newX: float, alien: Types.alien) : (bool, bool) => (true, true);

let alienStep = 70.;

let moveOnLeftEdge = (a: Types.alien) : Types.alien => a;

let moveOnRightEdge = (a: Types.alien) : Types.alien => a;

let moveAlien = (elapsedTime: float, a: Types.alien) : Types.alien => a;

let isStillInMap = (alien: Types.alien) => alien.y < Constants.height;

let moveAliens = (aliens: list(Types.alien), elapsedTime: float) : list(Types.alien) =>
  aliens |> List.map(moveAlien(elapsedTime)) |> List.filter(isStillInMap);

let reducer = (elapsedTime: float, state: Types.alienState, action: Actions.all) : Types.alienState =>
  switch action {
  | Tick => {...state, aliens: moveAliens(state.aliens, elapsedTime)}
  | _ => state
  };