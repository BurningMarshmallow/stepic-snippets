import Control.Monad(liftM, ap)

instance Functor Result where fmap = liftM
instance Foldable Result where
    foldr _ z (Error s) = z
    foldr f z (Ok a) = f a z
instance Traversable Result where
   traverse f (Error s)  = pure (Error s)
   traverse f (Ok a) = Ok <$> f a
instance Applicative Result where
  (<*>) = ap
  pure  = return
instance Monad Result where
  return x      = Ok x
  fail x        = Error x
  Ok a >>= f    = f a
  Error x >>= _ = Error x
