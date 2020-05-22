type t('a);

module Root = {
  [@react.component] [@bs.module "recoil"] external make: (~children: React.element) => React.element = "RecoilRoot";
};

type atomOption('a) = {
  key: string,
  default: 'a,
};
[@bs.module "recoil"] external atom: atomOption('a) => t('a) = "atom";
let atom = (~key, ~default) => atom({key, default});

type getter = {get: 'a. t('a) => 'a};
type selectorOption('a) = {
  key: string,
  get: getter => 'a,
};
[@bs.module "recoil"] external selector: selectorOption('a) => t('a) = "selector";
let selector = (~key, ~get) => selector({key, get});

[@bs.module "recoil"] external useRecoilState: t('a) => ('a, ('a => 'a) => unit) = "useRecoilState";
[@bs.module "recoil"] external useRecoilValue: t('a) => 'a = "useRecoilValue";
type setter('a) = 'a => 'a;
[@bs.module "recoil"] external useSetRecoilState: t('a) => setter('a) = "useSetRecoilState";