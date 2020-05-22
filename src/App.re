let textState = Recoil.atom(~key="textState", ~default="");
let charCountState = Recoil.selector(~key="charCountState", ~get=({get}) => get(textState) |> String.length);

module Input = {
  [@react.component]
  let make = () => {
    let (textValue, setTextValue) = Recoil.useRecoilState(textState);
    let onChange = React.useCallback(e => setTextValue(e->ReactEvent.Form.target##value));
    <div> <input value=textValue onChange /> </div>;
  };
};

module Show = {
  [@react.component]
  let make = () => {
    let textValue = Recoil.useRecoilValue(textState);
    let charCountValue = Recoil.useRecoilValue(charCountState);
    <> <div> {j|Echo: $(textValue)|j}->React.string </div> <div> {j|Character Count: $(charCountValue)|j}->React.string </div> </>;
  };
};

[@react.component]
let make = () => <Recoil.Root> <Input /> <Show /> </Recoil.Root>;