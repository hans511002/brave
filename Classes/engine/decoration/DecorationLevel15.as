package engine.decoration
{

    public class DecorationLevel15 extends Decoration
    {

        public function DecorationLevel15()
        {
            world.level.portal.stop();
            return;
        }// end function

        override public function update() : void
        {
            if (world.level.portal.currentFrame < world.level.portal.totalFrames)
            {
                world.level.portal.gotoAndStop((world.level.portal.currentFrame + 1));
            }
            else
            {
                world.level.portal.gotoAndStop(1);
            }
            super.update();
            return;
        }// end function

    }
}
