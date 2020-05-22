let nameState = Recoil.atom(~key="nameState", ~default="");
let charCountState = Recoil.selector(~key="charCountState", ~get=({get}) => get(nameState) |> String.length |> string_of_int);

module Input = {
  [@react.component]
  let make = () => {
    let (nameValue, setNameValue) = Recoil.useRecoilState(nameState);
    let onChange = React.useCallback(e => setNameValue(e->ReactEvent.Form.target##value));
    <div> <input value=nameValue onChange /> </div>;
  };
};

module Show = {
  [@react.component]
  let make = () => {
    let nameValue = Recoil.useRecoilValue(nameState);
    let charCountValue = Recoil.useRecoilValue(charCountState);
    <> <div> {j|Echo: $(nameValue)|j}->React.string </div> <div> {j|Character Count: $(charCountValue)|j}->React.string </div> </>;
  };
};

[@react.component]
let make = () => <Recoil.Root> <Input /> <Show /> </Recoil.Root>;