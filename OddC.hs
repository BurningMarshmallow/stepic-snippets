instance Functor OddC where
    fmap g (Un a)         = Un (g a)
    fmap g (Bi a b rest) = Bi (g a) (g b) (fmap g rest)
    
instance Foldable OddC where
    foldr f ini (Un a) = f a ini
    foldr f ini (Bi a b rest) =
        foldr f (f a (f b ini)) rest

instance Traversable OddC where
    traverse f (Un a) = Un <$> f a
    traverse f (Bi a b rest) = Bi <$> f a <*> f b <*> traverse f rest